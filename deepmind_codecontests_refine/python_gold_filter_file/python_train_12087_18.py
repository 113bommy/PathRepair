n = int(input())
arr = input()   # takes the whole line of n numbers
l = list(map(int,arr.split(' ')))
i = 0
for x in l:
    if x==1:
        print('hard')
        i = 1
        break
if i == 0:
    print('easy')