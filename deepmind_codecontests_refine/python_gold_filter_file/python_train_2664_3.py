p='ROYGBIV'
n=int(input())
ap=n//7
rem=n%7
last=["G", "GB", "YGB", "YGBI", "OYGBI" ,"OYGBIV" ]
p=p*ap
print(p+ last[rem-1] if rem>=1 else p)
