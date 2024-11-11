n=int(input())
lst=sorted(map(int,input().split()),reverse=True)
print(lst[n//2])
