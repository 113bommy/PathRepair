
t = int(input()) #кол-во данных
n = []
str1 = []
str2 = []

for i in range(t):
    n.append(int(input()))
    str1.append( list(input()))
    str2.append( list(input()))
for i in range(t):
   # print('--------------------------------')
   # print('-------------',i+1,'----------------')
    possibility = 'NO'
    for j in range(n[i]-2):
     #   print(str2[i][j+1], str1[i][j+1])
        #print(str2[i][j + 1] == 1)
        if str2[i][j+1] == '1' and str1[i][j +1] == '1':
            possibility = 'NO'
           # print('1')
            break
        else: possibility = 'YES'
    print(possibility)