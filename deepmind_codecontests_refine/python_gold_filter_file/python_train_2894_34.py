import sys

stdin = sys.stdin
na = lambda: map(int, stdin.readline().split())

def main():
  N, Q = na()

  ab = []
  for _ in range(N-1):
    a, b = na()
    ab.append([a, b])
  ab.sort()

  counter = [0] * (N+1)
  for _ in range(Q):
    p, x = na()
    counter[p] += x
  for i in range(N - 1):
    counter[ab[i][1]] += counter[ab[i][0]]
  print(*counter[1:])

if __name__ == "__main__":
  main()