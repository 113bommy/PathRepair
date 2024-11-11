#http://codeforces.com/contest/894/problem/B
#unsolved

n, m, k = list(map(int, input().split()))
j = 10**9 + 7

if k == -1 and (n + m) % 2 != 0:
   print(0)

else:
    print(pow(2, (n * m - m - (n - 1)),j))