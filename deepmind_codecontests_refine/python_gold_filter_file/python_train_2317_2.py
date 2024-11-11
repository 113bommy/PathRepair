from sys import stdin
input = stdin.readline

T = int(input())
while T > 0:
    T-=1;
    N = int(input())*2
    arr = list(map(int,input().split()))
    v = [[],[]]
    for i in range(0,N):
        ok = arr[i]%2
        v[ok].append(i)
    res = []
    for i in range(0,2):
        while len(v[i]) >= 2:
            res.append(v[i][-1])
            v[i].pop()
            res.append(v[i][-1])
            v[i].pop();
    for i in range(0,N//2-1):
        print(res[-1]+1,end=" ");
        res.pop();
        print(res[-1]+1);
        res.pop();