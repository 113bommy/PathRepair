s = input()
t = s.replace('BC', 'D') 
answer = 0
A = 0
for i in range(len(t)):
    if t[i] == 'A':
        A+=1
    elif t[i] == 'D':
        answer+=A
    else:
        A = 0

print(answer)