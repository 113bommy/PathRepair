import math


def get_num(): return list(map(int, input().rstrip().split()))
def rotate(list,num): return list[num:] + list[:num]

def main():
    list1 = get_num()
    list2 = get_num()


    answer = list(range(list1[0]+1))
    answer.pop(0)

    while(len(list2)>1):
        if(list2[0]<=list1[1]):
            list2.pop(0)
            answer.pop(0)

        else:
            list2[0]-=list1[1]
            list2 = rotate(list2,1)
            answer = rotate(answer,1)


    print(''.join(map(str,answer)))
main()


