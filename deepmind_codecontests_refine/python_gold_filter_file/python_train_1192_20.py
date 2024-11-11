s = input().lower()
text = input()
ind = 0
alpha = 'qwertyuiopasdfghjkl;zxcvbnm,./'
if s == 'l':
    for i in range(len(text)):
        ind = alpha.index(text[i])+1
        print(alpha[ind],end='')
elif s == 'r':
    for i in range(len(text)):
        ind = alpha.index(text[i])-1
        print(alpha[ind],end='')


