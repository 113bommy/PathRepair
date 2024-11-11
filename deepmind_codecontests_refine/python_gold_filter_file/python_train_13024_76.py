def Num_of_Coins():

    num , Sum = [int(x) for x in input("").split()]

    if(Sum%num==0):
        return int(Sum/num)
    else:
        return int(Sum/num) + 1 

print(Num_of_Coins())