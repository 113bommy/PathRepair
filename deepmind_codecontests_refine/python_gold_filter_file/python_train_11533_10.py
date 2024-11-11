from collections import deque
def main():
  h,w = map(int,input().split())
  ch,cw = map(lambda x:int(x)+1,input().split())
  dh,dw = map(lambda x:int(x)+1,input().split())
  s = [["#"]*(w+4) for _ in range(2)]+[["#"]*2+list(input())+["#"]*2 for _ in range(h)]+[["#"]*(w+4) for _ in range(2)]
  m1 = ((-1,0),(0,-1),(0,1),(1,0))
  m2 = [(i,j) for i in range(-2,3) for j in range(-2,3) if abs(i)+abs(j)>1]
  a = deque([(ch,cw)])
  b = deque()
  i = 0
  while a:
    while a:
      ah,aw = a.popleft()
      if s[ah][aw]!=".":
        continue
      b.append((ah,aw))
      s[ah][aw] = i
      for bh,bw in m1:
        bh,bw = ah+bh,aw+bw
        if s[bh][bw]==".":
          a.append((bh,bw))
    while b:
      ah,aw = b.popleft()
      for bh,bw in m2:
        bh,bw = ah+bh,aw+bw
        if s[bh][bw]==".":
          a.append((bh,bw))
    i += 1
  ans = s[dh][dw]
  print(ans if ans != "." else -1)

if __name__ == "__main__":
    main()