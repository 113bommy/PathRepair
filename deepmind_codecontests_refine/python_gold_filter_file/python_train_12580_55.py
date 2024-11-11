n,k=map(int,input().split())
lst=sorted(map(int,input().split()))

print(sum(lst[:-k-1:-1]))