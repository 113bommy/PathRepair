keyboard = ['q','w','e','r','t','y','u','i','o','p'
        ,'a','s','d','f','g','h','j','k','l',';'
            ,'z','x','c','v','b','n','m',',','.','/']

key = input()
c = 1
if key == 'R':
    c = -1

typeIn = input()

for char in typeIn:
    for i in range (0,30):
        if char == keyboard[i]:
            print(keyboard[i+c], end = '')

