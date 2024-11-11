#n, k = map(int, input().split(" "))
#LA = [int(x) for x in input().split()]

n, m, a, b = map(int, input().split(" "))
ans1 = (n % m) * b
ans2 = (m - (n % m)) * a
print(str(min(ans1,ans2)))


