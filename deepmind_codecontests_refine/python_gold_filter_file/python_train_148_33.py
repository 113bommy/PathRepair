from sys import stdin

def main():
  num = [ int(x) for x in stdin.readline().strip().split() ]
  s = sum(num)
  if s>0 and s%len(num)==0:
    print(s//len(num))
  else:
    print(-1)

main()
