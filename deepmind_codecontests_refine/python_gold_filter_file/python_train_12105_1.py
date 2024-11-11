import sys

for t in range(0,int(sys.stdin.readline())):
  nm = list(map(int,sys.stdin.readline().split()))
  rows = [list(map(int,sys.stdin.readline().split())) for t in range(0,nm[0])]
  cols = [list(map(int,sys.stdin.readline().split())) for t in range(0,nm[1])]
  cols0index=0
  for i in cols[0]:
    if i in rows[0]:
      cols0index=rows[0].index(i)
      break
  currow = [t[cols0index] for t in rows]
  rorder = [currow.index(cols[0][i]) for i in range(0,nm[0])]
  sys.stdout.write("\n".join([" ".join(list(map(str,rows[i]))) for i in rorder])+"\n")
  