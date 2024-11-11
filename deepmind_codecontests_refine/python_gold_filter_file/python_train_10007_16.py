s = str(input())
h = s.split(":")[0]
m = s.split(":")[1]
while(1):
    m = int(m) +1
    if m==60:
        m = 0
        h = int(h)+1
    if h==24:
        h=0
    h = '00' + str(h)
    m = '00' + str(m)
    if h[-2:] == m[-2:][::-1]:
        print(str(h[-2:])+":"+str(m[-2:]))
        break