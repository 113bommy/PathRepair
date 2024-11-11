x=input()
f=int(x)
s=int(x[0])
nums=['one','two','three','four','five','six','seven','eight','nine','ten','eleven','twelve','thirteen','fourteen','fifteen','sixteen','seventeen','eighteen','nineteen','twenty','thirty','forty','fifty','sixty','seventy','eighty','ninety']
if f==0:
    print("zero")
elif len(x) == 1:
    print(nums[f-1])
else:
    d=int(x[1])
    if f < 20 :
        print(nums[f-1])
    elif f%10 == 0:
        print(nums[s+17])
    else:
        print(nums[s+17]+"-"+nums[d-1])
