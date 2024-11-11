def solve(c,v0,v1,a,l):
  count = 0
  c -= v0
  count +=1
  if c <= 0:
    return count
  d = 1
  c += l
  while True:
    val = d*a+v0
    if val > v1:
      val = v1
    c -= val
    count += 1
    d += 1
    if c <= 0:
      return count
    c+=l

    

  
def main() :
  arr = list(map(int, input().split(' ')))
  # n = int(input())
  # arr = []
  # for _ in range(n):
  #   i = list(map(int, input().split(' ')))
  #   arr.append(i)
  print(solve(*arr))
main()
