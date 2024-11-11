n = int(input())

for i in range(n):
    s = input()
    if s[-2::1] == 'po':
        print('FILIPINO')
    elif s[-4::1] == 'desu' or s[-4::1] == 'masu':
        print('JAPANESE')
    elif(s[-5::1]) == 'mnida':
        print('KOREAN')
