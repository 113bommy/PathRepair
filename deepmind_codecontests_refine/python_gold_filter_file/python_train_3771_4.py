import sys
import math
input = sys.stdin.readline
from functools import cmp_to_key;

def pi():
    return(int(input()))
def pl():
    return(int(input(), 16))
def ti():
    return(list(map(int,input().split())))
def ts():
    s = input()
    return(list(s[:len(s) - 1]))
def invr():
    return(map(int,input().split()))
mod = 998244353;
f = [];
def fact(n,m):
    global f;
    f = [1 for i in range(n+1)];
    f[0] = 1;
    for i in range(1,n+1):
        f[i] = (f[i-1]*i)%m;

def fast_mod_exp(a,b,m):
    res = 1;
    while b > 0:
        if b & 1:
            res = (res*a)%m;
        a = (a*a)%m;
        b = b >> 1;
    return res;

def inverseMod(n,m):
    return fast_mod_exp(n,m-2,m);

def ncr(n,r,m):
    if r == 0: return 1;
    return ((f[n]*inverseMod(f[n-r],m))%m*inverseMod(f[r],m))%m;

def main():
    stringColoring();

def xdfs(root, v, sub, parent):
    st = [root];
    while len(st) > 0:
        node = st.pop();
        for i in range(len(v[node])):
            if v[node][i] != node:
                st.append(v[node][i]);


def X():
    try:
        t = pi();
        while t:
            t -= 1;
            n = pi();
            v = [[] for i in range(n)];
            for i in range(n-1):
                [x,y] = ti();
                v[x-1].append(y-1);
                v[y-1].append(x-1);
            m = pi();
            p = ti();
            e = [0 for i in range(n-1)];
            sub = [0 for i in range(n)];
            dfs(0,v,sub,-1)
            for i in range(1,n):
                e[i-1] = (sub[i]*(n-sub[i]));
            if len(p) < n-1:
                while len(p) < n-1:
                    p.append(1);
            p = sorted(p);    
            if len(p) > n-1:
                x = 1;
                for i in range(n-2,len(p)):
                    x = (x*p[i]);
                while len(p) > n-2:
                    p.pop();
                p.append(x);

            e = sorted(e);
            res = 0;
            for i in range(n-1):
                res = (res+(p[i]*e[i]))%mod;
            print(res);
    except:
        print(sys.exc_info());

def bfs(v,root):
    q = [root,None];
    l = 0;
    visited = [0 for i in range(len(v))];
    dist = [0 for i in range(len(v))];
    while len(q) > 0:
        node = q.pop(0);
        if node is not None:
            visited[node] = 1;
            dist[node] = l;
            for i in range(len(v[node])):
                if visited[v[node][i]] == 0:
                    visited[v[node][i]] = 1;
                    q.append(v[node][i]);
        else:
            l += 1;
            if len(q) != 0:
                q.append(None);
    return dist;


def B():
    n = pi();
    v = [[] for i in range(n)];
    for i in range(n-1):
        [x,y] = ti();
        v[x-1].append(y-1);
        v[y-1].append(x-1);
    leafs = [];
    for i in range(n):
        if len(v[i]) == 1:
            leafs.append(i);

    mn = 1;
    d = bfs(v,leafs[0]);
    for i in range(1,len(leafs)):
        if d[leafs[i]] % 2 != 0:
            mn = 3;
            break;
    count = 0;
    for i in range(n):
        f = 0;
        for j in range(len(v[i])):
            if len(v[v[i][j]]) == 1:
                f = 1;
                break;
        if f: count += 1;
    mx = n-1-len(leafs)+count;
    print(mn,mx)


def KMP(s):
    a = [0 for i in range(len(s))];
    i = 0;
    j = 1;
    while j < len(s):
        if s[i] == s[j]:
            a[j] = i+1;
            i += 1;
            j += 1;
        else:
            i = a[j-1];
            if s[i] == s[j]:
                a[j] = i+1;
                i += 1;
                j += 1;
            else:
                j += 1;
    return a;

def getLargetPrefixPallindrome(s):
    r = str(s)[::-1];
    a = KMP(str(s) + "?" + r);
    return str(s[0:a[2*len(s)]]);

def D2():
    t = pi();
    while t:
        t -= 1;
        s = input();
        s = s[:len(s) - 1];
        l = 0;
        n = len(s);
        if len(s) == 1:
            print(s);
            continue;
        for i in range(len(s)):
            if s[i] == s[n-i-1]:
                l += 1;
                continue;
            break;
        pre = getLargetPrefixPallindrome(s[l:-l] if l != 0 else s);
        suf = getLargetPrefixPallindrome(str(s[l:-l])[::-1] if l != 0 else s[::-1]);
        if len(pre) > len(suf):
            print(str(s[0:l])+pre+str(s[n-l:len(s)]));
        else:
            print(str(s[0:l])+str(suf[::-1])+str(s[n-l:len(s)]));

def D():
    t = pi();
    while t:
        t -= 1;
        [n,s] = input().split(" ");
        s = s[:len(s)-1];
        n = int(n);
        mx = [-1 for i in range(n)];
        i = 0;
        x = 1;
        while i < n-1:
            while i < n-1 and s[i] == ">":
                i += 1;
            mx[i] = x;
            j = i-1
            while j >= 0 and mx[j] == -1:
                x += 1;
                mx[j] = x;
                j -= 1;
            i += 1;
            x += 1;
        i = n-1;
        x = 1;
        mn = [-1 for i in range(n)];
        f = 0;
        while i >= 1:
            if i >= 1 and i < len(s) and s[i] == "<" and s[i-1] == ">":
                mn[i] = x;
                x += 1;

            i -= 1;
        if x != 1:
            for i in range(n-1,-1,-1):
                if mn[i] == -1:
                    mn[i] = x;
                    x += 1;
        else:
            if s[0] == "<":
                for i in range(n):
                    mn[i] = x;
                    x += 1;
            else:
                x = n;
                for i in range(n):
                    mn[i] = x;
                    x -= 1;
            
        print(*mn, sep=" ");
        print(*mx, sep=" ");

def cmp(a,b):
    if ord(a[1]) < ord(b[1]): return -1;
    if ord(a[1]) > ord(b[1]): return 1;
    if ord(a[1]) == ord(b[1]):
        if a[0] < b[0]: return -1;
        if a[0] < b[0]: return 1;
        return 0;
    return 0;

def stringColoring():
    n,s = pi(),ts();
    dp = [[[0 for k in range(26)] for j in range(26)] for i in range(n+1)];
    p = [[[[] for k in range(26)] for j in range(26)] for i in range(n+1)];
    dp[0][0][0] = 1;
    for i in range(n):
        c = ord(s[i])-ord("a");
        for c1 in range(26):
            for c2 in range(26):
                if dp[i][c1][c2] == 0: continue;
                if c >= c1:
                    dp[i+1][c][c2] = 1;
                    p[i+1][c][c2] = [[c1,c2],0];
                if c >= c2:
                    dp[i+1][c1][c] = 1;
                    p[i+1][c1][c] = [[c1,c2],1];


    x,y = -1,-1;
    for i in range(26):
        for j in range(26):
            if dp[n][i][j]:
                x = i;
                y = j;
    if x == -1:
        print("NO");
        return;

    res = "";
    px = -1;
    py = -1;
    for i in range(n, 0, -1):
        px = p[i][x][y][0][0];
        py = p[i][x][y][0][1];
        if p[i][x][y][1]: res += "1";
        else: res += "0";
        x,y = px,py;
    print("YES");
    print(res[::-1]);

    

main();