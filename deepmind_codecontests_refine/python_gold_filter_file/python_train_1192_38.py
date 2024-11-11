direction = input()
text = input()

keyboard = 'qwertyuiopasdfghjkl;zxcvbnm,./'

ans = ''
if direction == 'R':
    for c in text:
        ans += keyboard[keyboard.index(c) - 1]
else:
    for c in text:
        ans += keyboard[keyboard.index(c) + 1]

print(ans)
        
