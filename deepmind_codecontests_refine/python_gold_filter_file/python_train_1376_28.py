t = int(input())
l = []
for i in range(t):
    a = input()
    s = a[-2::]
    if a[-2::]=='po':
        l.append('FILIPINO')
    elif a[-4::]=='desu' or a[-4::] =='masu':
        l.append("JAPANESE")
    elif a[-5::]=='mnida':
        l.append('KOREAN')
for i in l:
    print(i)