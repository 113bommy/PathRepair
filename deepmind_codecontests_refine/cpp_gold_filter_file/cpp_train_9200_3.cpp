#include <bits/stdc++.h>
using namespace std;
typedef struct Operacao {
  int32_t inicio, fim;
  int64_t valor;
} op_t;
void prefix_sum(int64_t *lista, const int32_t inicio, const int32_t fim,
                const int64_t valor) {
  lista[inicio] += valor;
  lista[fim + 1] -= valor;
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int32_t tamanho, qtde_operacoes, qtde_consultas, i, inicio, fim;
  cin >> tamanho >> qtde_operacoes >> qtde_consultas;
  int64_t prefix_array[tamanho + 1], op_prefix_array[qtde_operacoes + 1], valor;
  op_t operacoes[qtde_operacoes];
  int32_t anterior = 0;
  for (i = 0; i < tamanho; i++) {
    cin >> valor;
    prefix_array[i] = valor - anterior;
    anterior = valor;
  }
  for (i = 0; i < qtde_operacoes; i++) {
    cin >> operacoes[i].inicio >> operacoes[i].fim >> operacoes[i].valor;
    op_prefix_array[i] = 0;
  }
  for (i = 0; i < qtde_consultas; i++) {
    cin >> inicio >> fim;
    prefix_sum(op_prefix_array, inicio - 1, fim - 1, 1);
  }
  valor = 0;
  for (i = 0; i < qtde_operacoes; i++) {
    valor += op_prefix_array[i];
    prefix_sum(prefix_array, operacoes[i].inicio - 1, operacoes[i].fim - 1,
               operacoes[i].valor * valor);
  }
  valor = 0;
  for (i = 0; i < tamanho - 1; i++) {
    valor += prefix_array[i];
    cout << valor << " ";
  }
  valor += prefix_array[i];
  cout << valor << "\n";
  return 0;
}
