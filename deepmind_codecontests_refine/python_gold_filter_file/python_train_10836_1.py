n = int(input())
a=  list(map(int,input().split()))
sum, cur = a[0] % 998244353, a[0]

for x in a[1:]:
    sum  = sum * 2 + cur + x
    cur = cur * 2 + x
    sum %= 998244353
    cur %= 998244353
print(sum)