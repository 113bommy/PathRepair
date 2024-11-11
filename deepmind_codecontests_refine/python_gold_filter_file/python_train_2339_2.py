#rock pair scissor
f = input();
m = input();
s = input();
if f=='rock' and m=='scissors' and s=='scissors':
    print('F')
elif m=='rock' and f=='scissors' and s=='scissors':
    print('M')
elif s=='rock' and f=='scissors' and m=='scissors':
    print('S')
elif f=='scissors' and m=='paper' and s=='paper':
    print('F')
elif m=='scissors' and f=='paper' and s=='paper':
    print('M')
elif s=='scissors' and f=='paper' and m=='paper':
    print('S')
elif f=='paper' and m=='rock' and s=='rock':
    print('F')
elif m=='paper' and f=='rock' and s=='rock':
    print('M')
elif s=='paper' and f=='rock' and m=='rock':
    print('S') 
else:
    print('?')