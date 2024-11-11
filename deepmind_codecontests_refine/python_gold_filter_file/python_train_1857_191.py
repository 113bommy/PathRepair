input()
a = list(map(int,input().split()))
a.sort(reverse = True)
print(sum(a[0::2]) - sum(a[1::2]))
