# coding: utf-8
n = int(input())
s = input()
for i in range(n):
    if s[i] != '*':
        continue
    for j in range(i+1,n):
        if s[j] != '*':
            continue
        dis = j-i
        if i+2*dis < n and s[i+2*dis]=='*' and\
           i+3*dis < n and s[i+3*dis]=='*' and\
           i+4*dis < n and s[i+4*dis]=='*':
            print('yes')
            exit()
print('no')
