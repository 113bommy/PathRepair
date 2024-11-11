input_1st=input()
input_2nd=input()

N, K = input_1st.split(" ")
D = input_2nd.split(" ")

for ans in range(int(N), 100000):
    flg = True
    for i in range(len(str(ans))):
        if str(ans)[i] in D:
          flg = False
          break

    if flg:
        print(ans)
        break
