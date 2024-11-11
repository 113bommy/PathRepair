franxx = input()
franxx = franxx.split()

pa_U_dara = int(franxx[0])
life = int(franxx[1])

darling = input()
darling = darling.split()

darling[0] = int(darling[0])

kaguya = darling[0]
chika = -darling[0]

for i in range(1, life):
	darling[i] = int(int(darling[i]) + darling[i - 1])
	kaguya = darling[i]
	chika = max(chika, -kaguya)

flat = 0
if (kaguya != 0):
	flat = max(0, -(max(pa_U_dara - chika, 0) // kaguya))
	
pa_U_dara += kaguya * flat

chest = -1
flat *= life

for i in range(0, life):
	if (pa_U_dara + darling[i] <= 0):
		chest = i + 1
		break

print(flat + chest)