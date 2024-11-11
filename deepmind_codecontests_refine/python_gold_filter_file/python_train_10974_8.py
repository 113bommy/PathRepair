n = int(input())

if n==1:
    print("1")
    print("C")
elif n%2 ==0 :
    temp = int(n/2)
    s1  = "C."
    s1 = s1*temp
    s2= ".C"
    s2 = s2*temp

    ans = n * int(n/2)
    print(int(ans))

    for i in range(temp):
        print(s1)
        print(s2)
else:
    temp = int(n/2)
    s1  = "C."
    s1 = s1*temp
    s1 += "C"

    s2= ".C"
    s2 = s2*temp
    s2+= "."

    ans = int(n/2)*int(n/2)
    ans += (int(n/2)+1)*(int(n/2)+1)
    print(int(ans))

    for i in range(temp):
        print(s1)
        print(s2)
    print(s1)