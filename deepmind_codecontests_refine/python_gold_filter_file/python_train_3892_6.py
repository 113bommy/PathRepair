def GreedyGirl(str):
    odd = list(str)

    temp = [item for item in odd if odd.count(item)%2!=0]

    OddOneOut  = len(set(temp))

    if OddOneOut == 0 or OddOneOut%2==1:
        print('First ')
    else:
        print('Second')

GreedyGirl(input())