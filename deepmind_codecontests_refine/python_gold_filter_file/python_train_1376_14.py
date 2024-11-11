fil = ['po']
jap = ['desu', 'masu']
kor = ['mnida']

for i in range(int(input())):
    l = input()
    if l[len(l)-2:] in fil:
        print("FILIPINO")
    elif l[len(l)-4:] in jap:
        print("JAPANESE")
    else:
        print("KOREAN")