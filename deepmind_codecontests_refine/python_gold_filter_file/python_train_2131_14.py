a = int(input())
for i in range(1, 100):
    if -1 != str(a + i).find('8'):
        print(i)
        break
