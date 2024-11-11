import math
def solve(n):
  if n <= 2:
    return [-1]
  return [i for i in range(n,0,-1)]
  
def main() :
  n = int(input())
  # arr = list(map(int, input().split(' ')))
  # arr = []
  # for _ in range(3):
  #   arr.append(input())
  print(*solve(n))
main()
