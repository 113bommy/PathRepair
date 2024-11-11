numlist = list(input().split())
print(sorted(numlist,key=lambda x:numlist.count(x))[0]) 