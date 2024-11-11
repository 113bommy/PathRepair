test=int(input())
for i in range(test):
    str_=input()
    string=list(str_)
    n=len(string)
    max_so_far=0
    curr_so_far=1
    flag=0
    for i in range(0,n):
        if i<n-1 and string[i]==string[i+1] and string[i]=="L":
            curr_so_far+=1
        else:
            if (max_so_far<curr_so_far):
                max_so_far=curr_so_far
            curr_so_far=1 
        if string[i]=="L":
            flag=1
    if flag==0:
        print("1")
    else:
        print(max_so_far+1)