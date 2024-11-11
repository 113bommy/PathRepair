available = input()
request = input()


available_array = [int(numeric_string) for numeric_string in str.split(available,' ')]
request_array = [int(numeric_string) for numeric_string in str.split(request, ' ')]

res= [i - j for i, j in zip(available_array, request_array)]

comp=0

for x in res:
    if(x<0):
        comp+=x*2
    else:
        comp+=int(x/2)*2

if(comp<0):
    print("No")
else:
    print("Yes")