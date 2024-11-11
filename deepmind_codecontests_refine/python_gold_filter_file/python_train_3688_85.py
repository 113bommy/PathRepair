n=int(input())
list1= list(map(int, input().split()))
a,b = map(int, input().split())
c=b-a
d=sum(list1[a-1:b-1])
print(d)