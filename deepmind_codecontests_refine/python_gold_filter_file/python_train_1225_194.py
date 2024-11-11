n,k = map(int,input().split())
li = list(map(int,input().split()))

li.sort()
print(sum(li[:k]))