n = int(input())
answers = list(map(int, input().split()))

sum = 0

for i in answers:
    sum += i
    
if sum == 0:
    print('EASY')
else:
    print('HARD')
