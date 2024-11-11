
word = input()
cnt = 0
cur = 97
for i in word :
    i = ord(i)
    if abs(i-cur)>13:
        cnt +=13-(abs(cur-i)-13)
        
    elif abs(i-cur)<= 13:
        cnt += abs(i-cur)
        
    cur = i
print(cnt)