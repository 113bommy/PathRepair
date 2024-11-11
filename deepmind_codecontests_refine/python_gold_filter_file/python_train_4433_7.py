import sys

def is2power(num):
    return ((num & (num - 1)) == 0) and num > 0

array=[]
for i in range(5):
    array.append(0)

number = int(input())
inGenome = list(input())

maxAppear = number/4


# [A,C,G,T,?]
for letter in inGenome:
    if letter == 'A':
        array[0]+=1
    if letter == 'G':
        array[1]+=1
    if letter == 'C':
        array[2]+=1
    if letter == 'T':
        array[3]+=1
    if letter == '?':
        array[4]+=1


for letter in inGenome:
    if letter == '?':
        for i in range(4):
            if array[i] < maxAppear:
                if i == 0:
                    inGenome[inGenome.index(letter)] = 'A'
                    array[0]+=1
                    #print(inGenome)
                elif i == 1:
                    inGenome[inGenome.index(letter)] = 'G'
                    array[1]+=1
                    #print(inGenome)
                elif i == 2:
                    inGenome[inGenome.index(letter)] = 'C'
                    array[2]+=1
                    #print(inGenome)
                elif i == 3:
                    inGenome[inGenome.index(letter)] = 'T'
                    array[3]+=1
                    #print(inGenome)
                array[4]-=1
                break


if (array[4] > 0) or (array[0] > maxAppear) or (array[1] > maxAppear or (array[2] > maxAppear) or (array[3] > maxAppear)):
    print('===')
else:
    print(''.join(inGenome))
