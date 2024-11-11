import sys
n = int(input())
string = input().split()
cnt2 = 0
for char in string:
    cnt = 0
    #print(char)
    for letter in char:
        if ord(letter) >= 65 and ord(letter) <= 90:
            cnt += 1
    if cnt > cnt2:
        cnt2 = cnt
print(cnt2)