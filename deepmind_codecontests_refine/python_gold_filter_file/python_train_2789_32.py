n = int(input())
l = list(map(int, input().split()))

print(sum(l[i]*x for i in range(len(l)-1) for x in l[i+1:]))
