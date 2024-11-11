for _ in range(0, int(input())):
     n, m = map(int, input().split())
     mat = [[char for char in input()] for _ in range(0, n)]
     answer = []

     def update(changes):
          answer.append((changes[0], changes[1], changes[2]))
          for x, y in changes:
               if mat[x][y] == '0':
                    mat[x][y] = '1'
               else:
                    mat[x][y] = '0'
     
     def change(a, b, c, vec0, vec1):
          answer.append((a, b, c))
          for x, y in [a, b, c]:
               if mat[x][y] == '0':
                    vec0.remove((x, y))
                    vec1.append((x, y))
                    mat[x][y] = '1'
               else:
                    vec0.append((x, y))
                    vec1.remove((x, y))
                    mat[x][y] = '0'
          return vec0, vec1
     if n > 2 or m > 2:
          for x in range(0, n, 2):
               for j in range(0, m - 1, 1):
                    i = min(n - 2, x)
                    if mat[i][j] == '0' and mat[i + 1][j] == '0':
                         continue
                    changes = []
                    if mat[i][j] == '1':
                         changes.append((i, j))
                    if mat[i + 1][j] == '1':
                         changes.append((i + 1, j))
                    if len(changes) < 3:
                         changes.append((i, j + 1))
                    if len(changes) < 3:
                         changes.append((i + 1, j + 1))
                    update(changes)
          for x in range(0, n - 2):
               i = x
               j = m - 2
               if mat[i][j] == '0' and mat[i][j + 1] == '0':
                    continue
               changes = []
               if mat[i][j] == '1':
                    changes.append((i, j))
               if mat[i][j + 1] == '1':
                    changes.append((i, j + 1))
               if len(changes) < 3:
                    changes.append((i + 1, j))
               if len(changes) < 3:
                    changes.append((i + 1, j + 1))
               update(changes)
     a = n - 2
     b = m - 2
     vec0 = [(x, y) for x in range(a, a + 2) for y in range(b, b + 2) if mat[x][y] == '0']
     vec1 = [(x, y) for x in range(a, a + 2) for y in range(b, b + 2) if mat[x][y] == '1']
     cnt = 0
     while len(vec1) > 0:
          if len(vec1) == 4:
               vec0, vec1 = change(vec1[0], vec1[1], vec1[2], vec0, vec1)
          elif len(vec1) == 3:
               vec0, vec1 = change(vec1[0], vec1[1], vec1[2], vec0, vec1)
          else:
               vec0, vec1 = change(vec0[0], vec0[1], vec1[0], vec0, vec1)
     print(len(answer))
     for x, y, z in answer:
          print(x[0] + 1, x[1] + 1, y[0] + 1, y[1] + 1, z[0] + 1, z[1] + 1)
