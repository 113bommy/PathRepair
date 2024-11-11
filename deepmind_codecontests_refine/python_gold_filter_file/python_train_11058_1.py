t=int(input())
for g in range(t):
    n=int(input())
    q=sorted(int(f)for f in input().split())
    if n%2:
        print(q[n]-q[n-1])
    else:
        print(q[n]-q[n-1])
