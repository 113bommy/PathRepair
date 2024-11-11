def getLuckyCount(num) :
    return len([i for i in num if i == '4' or i == '7'])

n , k = map(int , input().split(" "))
numbers = input().split(" ")

print(len([i for i in numbers if getLuckyCount(i) <= k]))
