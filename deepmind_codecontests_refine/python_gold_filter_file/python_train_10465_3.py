#!/usr/bin/python3

tmp = input().split(" ");
r = int(tmp[0])
c = int(tmp[1])
n = int(tmp[2])
k = int(tmp[3])

tab = [[0]]

for j in range(1,c+1):
  tab[0].append(0)

for i in range(1,r+1):
  tab.append([0])
  for j in range(1,c+1):
    tab[i].append(0)

for i in range(0,n):
  tmp = input().split(" ")
  tab[ int(tmp[0]) ][ int(tmp[1]) ] = 1

pre = tab

for i in range(1,r+1):
  for j in range(1,c+1):
    pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + tab[i][j]

wynik = 0
for i in range(1,r+1):
  for j in range(1,c+1):
    for ii in range(i,r+1):
      for jj in range(j,c+1):
        if tab[ii][jj] - tab[i-1][jj] - tab[ii][j-1] + tab[i-1][j-1] >= k:
          wynik = wynik + 1

print ( wynik )

