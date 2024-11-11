n, m = map(int, input().split())
s, t, ans, k = str(input()), str(input()), n + 1, []
def f(y):
  return sum([(s[i] != y[i]) for i in range(n)])
for i in range(m - n + 1):
  if ans > f(t[i : i + n]):
    ans = f(t[i : i + n])
    k = [str(j + 1) for j in range(n) if s[j] != (t[i : i + n])[j]]
print(ans, "\n" + " ".join(k))