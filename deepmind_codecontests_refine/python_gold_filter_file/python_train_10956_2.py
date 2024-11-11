from sys import stdin, stdout

for _ in range(int(stdin.readline())):
  n, m = map(int, stdin.readline().split())
  median = (2**m -n- 1)//2
  countless = 0
  countlarge = 0
  arr = [int(stdin.readline(),2) for i in range(n)]
  arr.sort()
  for i in arr:
    if i <= median:
      median+=1

  median = bin(median)[2:]
  if m > len(median):
      stdout.write("0"*(m-len(median))+median+"\n")
  else:
      stdout.write(median+"\n")