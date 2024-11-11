n=int(input())
nl=sorted(list(map(int, input().split())),reverse=True)
print(sum(nl[0::2])-sum(nl[1::2]))