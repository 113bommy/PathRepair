N = int(input())
a = sorted(list(map(int,input().split())), reverse=True)
print(sum(a[0::2])-sum(a[1::2]))