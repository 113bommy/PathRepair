import sys
input = sys.stdin.readline
def sep(): return map(int,input().split())
"""
def main():
    t = int(input())
    for _ in range(t):
        n,m = sep()
        a=list(sep())
        b=list(sep())
        ans=0
        a = sorted(a,reverse=True)
        for i in range(n):
            if a[i]>=i+1:
                ans+=b[i]
            else:
                ans+=b[a[i]-1]
        print(ans)
if __name__ == '__main__':
    main()
"""

"""
def main():
    n=int(input())
    x = int(input())
    p=7-x
    for i in range(n):
        c = list(sep())
        if x in c or p in c:
            print("NO")
            break
    else:
        print("YES")
if __name__ == '__main__':
    main()
"""
def main():
    s,k = sep()
    a=[0,1]
    ans=[]
    #print(ans)
    while(a[-1]<s):
        a.append(sum(a[-k:]))
    a.reverse()
    #print(list(a))
    for i in a:
        if i<=s:
            ans.append(i)
            s-=i
    print(len(ans))
    print(*ans)
if __name__ == '__main__':
    main()