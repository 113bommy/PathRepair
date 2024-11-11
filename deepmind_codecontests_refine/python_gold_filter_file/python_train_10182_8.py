def exchange(n, s, d):
  v = [n] * (n + 1)
  r = [(1, 1)] + [(a, b) for a, b in zip(s, d) if a < b]

  for i in range(len(v) - 1):
    for a, b in r:
      if i + a < len(v):
        v[i + a] = max(v[i] - a + b, v[i + a])

  return v[-1]


def main():
  n = int(input())
  a = list(map(int, input().split()))
  b = list(map(int, input().split()))

  n = exchange(n, a, b)
  n = exchange(n, b, a)

  print(n)


if __name__ == '__main__':
  main()
