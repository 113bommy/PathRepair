n = int(input())
l = [int(i) for i in input().split()]
a,b = [int(i) for i in input().split()]
print(sum(l[a-1:b-1]))
