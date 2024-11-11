# # import numpy as np
#
# def spliter(arr,low,high):
#     if(high-low==1):
#         # print("1")
#         return 1
#
#     if(arr[low:high]==sorted(arr[low:high])):
#         # print("here "+str(high-low))
#         return high-low
#     else:
#         mid=(high+low)//2
#         # print("----------")
#         # print((low,mid))
#         # print("---------")
#         # print((mid,high))
#         # print("-----------")
#         a=spliter(arr,low,mid)
#         # print("was here")
#         b=spliter(arr,mid,high)
#
#         # print((a,b))
#         if(a>=b):
#             return a
#         else:
#             return b
#
# def main():
#     n=int(input())
#     arr=list(map(int,input().split(" ")))
#     lenght = n
#     if arr==sorted(arr):
#         print(n)
#     else:
#         mid=lenght//2
#         a=spliter(arr,0,mid)
#         b=spliter(arr,mid,lenght)
#         if(a>b):
#             print(a)
#         else:
#             print(b)
#
# main()


# def main():
#     checker="nineteen"
#     # n="nneteenabcnneteenabcnneteenabcnneteenabcnneteenabcii"
#     n=input()
#     number={}
#     # print(set(n))
#     for i in n:
#         if i in checker:
#             number[i]=number.get(i,0)+1
#     # number=sorted(number.values())
#     # print(sorted(number.keys()))
#     for i in ["n","t","i","e"]:
#         if i not in number.keys():
#             break
#
#     else:
#         num=number["i"]
#         min=num
#         other_Dict={"n":3,"i":1,"e":3,"t":1}
#         if(number["n"]%3==2):
#             number["n"]=number.get("n",0)+number["n"]//3
#
#         for i in number.keys():
#             if (number[i]//other_Dict[i]>=num):
#                 pass
#             elif(number[i]//other_Dict[i]<=num):
#
#                 if(min>number[i]//other_Dict[i]):
#                     min=number[i]//other_Dict[i]
#         else:
#             print(min)
#             return
#     print(0)
# main()
        # return False
    # for i,j in number:
    #     if i=="n" and i
#     # print(number)
# print(main())
# main()
# d={}
# d[10]=1
# d[10]+=2
# d[10].append(10)
# 2//3
# d.get(10,5)
# d.keys()
# main()
# d={}
# for i in "nineteen":
#    d[i]=d.get(i,0)+1
# d
# "i" not in d.keys()
# some="nineoindojaoidjoiajdoiaoidjiadjkajoidjoiajdljadjoiadlkjaadj"
# list(some.split("nineteen"))


def main():
    n=list(map(int,input().split(" ")))
    navigation=[]
    for i in range(n[1]-n[2],n[1]):
        if(i>0):
            navigation.append(i)
    for i in range(n[1],n[1]+n[2]+1):
        if(i<=n[0]):
            navigation.append(i)
    if(navigation[0]>1):
        navi=[0]*len(navigation)
        navi[0]="<<"
        navi[1:len(navigation)]=navigation
        navigation=navi
    if(navigation[len(navigation)-1]<n[0]):
        navigation.append(">>")
    string=""
    for i in navigation:
        if(str(i)==str(n[1])):
            string+="({}) ".format(i)
        else:
            string+="{} ".format(i)
    print(string[:-1])
main()




