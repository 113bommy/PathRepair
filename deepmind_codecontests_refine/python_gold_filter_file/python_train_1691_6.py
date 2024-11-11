import sys
input = lambda: sys.stdin.readline().rstrip()
inp = sys.stdin.buffer.readline                                
def I(): return list(map(int,inp().split()))

for _ in range(I()[0]):
    n=int(input())
    a=[int(i) for i in input().split()]
    f=n ; ans='Yes'
    for i in range(n-1):
        if a[i]==f: 
            f=n-i-1
        elif a[i]+1==a[i+1]:
            continue
        else:
            ans='No'
            break
    print(ans)