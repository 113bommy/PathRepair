'''
Codeforces: B. Table Tennis
'''

def queue(list_, k):
    wins = 0
    while wins < k:
        if int(list_[0]) > int(list_[1]):
            index = 1
            wins+=1
        else:
            index = 0
            wins = 1
        list_.append(list_[index])
        list_.pop(index)
    
    return list_[0]

first = input().split()
k = int(first[1])
list_ = input().split()
if k > len(list_)-1:
    k = len(list_)-1
print(queue(list_, k))