n,k = map(int,input().split())
a = list(map(int,input().split()))

s = sorted(a,reverse=True)
mod = 10**9 + 7
ans = 1
#全部の要素が負の数であり奇数個の場合は大きい順に取ったものが答え
if k % 2 == 1 and s[0] < 0:
        for i in range(k):
            ans = ans * s[i] % mod
        print(ans)
        exit()#終了

l = 0
r = n - 1
#次の処理のための計算　（kが奇数だった場合)
#この処理の必要性
#奇数個だった場合三個のうち二つで正の数の最大値を作れば良い
if k % 2 == 1:
  ans = ans * s[l]
  l += 1


for _ in range(k // 2):
  ml = s[l] * s[l + 1]
  mr = s[r] * s[r - 1]
  if ml > mr:
    ans = ans * ml % mod
    l += 2
  else:
    ans = ans * mr % mod
    r -= 2

print(ans)
