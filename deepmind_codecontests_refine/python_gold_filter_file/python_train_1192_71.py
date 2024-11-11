shift = input()
s = input()
keyboard = ['q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l',';','z','x','c','v','b','n','m',',','.','/']
change = 0
if shift == 'R':
    change-=1
else:
    change+=1
answer = ''
for element in s:
    if change == 1 and element == '/':
        answer += 'q'
    else:
        answer += keyboard[keyboard.index(element)+change]
print(answer) 